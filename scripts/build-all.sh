#!/usr/bin/env bash
# Walks every example directory and builds it with whichever build tool it
# uses (justfile / meson.build / CMakeLists.txt / Makefile), so CI catches
# broken examples the same way a contributor would find them: by building.
set -uo pipefail

root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$root"

# Directories that can't reasonably be built in a stock CI environment:
# they need hardware, a toolchain, or a library that isn't available there.
SKIP=()

should_skip() {
  local dir="$1"
  for skip in "${SKIP[@]}"; do
    [[ "$dir" == "$skip" ]] && return 0
  done
  return 1
}

failures=()
built=0
skipped=0

for entry in */; do
  dir="${entry%/}"
  [[ -d "$dir" ]] || continue

  if should_skip "$dir"; then
    echo "== skip: $dir =="
    skipped=$((skipped + 1))
    continue
  fi

  if [[ -f "$dir/justfile" || -f "$dir/Justfile" ]]; then
    echo "== build ($dir): just =="
    (cd "$dir" && just build) || failures+=("$dir")
    built=$((built + 1))
  elif [[ -f "$dir/meson.build" ]]; then
    echo "== build ($dir): meson =="
    (
      cd "$dir" &&
        { [[ -d build ]] || meson setup build; } &&
        meson compile -C build
    ) || failures+=("$dir")
    built=$((built + 1))
  elif [[ -f "$dir/CMakeLists.txt" ]]; then
    echo "== build ($dir): cmake =="
    (cd "$dir" && cmake -S . -B build && cmake --build build) || failures+=("$dir")
    built=$((built + 1))
  elif [[ -f "$dir/Makefile" ]]; then
    echo "== build ($dir): make =="
    (cd "$dir" && make) || failures+=("$dir")
    built=$((built + 1))
  else
    echo "== no build file, skipping: $dir =="
  fi
done

echo "== build (root): cmake =="
(cmake -S . -B build && cmake --build build) || failures+=("root")
built=$((built + 1))

echo
echo "Built $built directories, skipped $skipped."
if [[ ${#failures[@]} -gt 0 ]]; then
  echo "FAILED: ${failures[*]}"
  exit 1
fi
echo "All good."
