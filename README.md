# LeetCode Solutions

This repository collects LeetCode practice solutions in multiple languages, plus a few adjacent study tracks and reference notes.

The main archive lives in the difficulty folders:

- `Easy`
- `Medium`
- `Hard`

Additional folders currently contain supporting material:

- `30DaysOfJavascript`: JavaScript practice track solutions
- `IntroductionToPandas`: pandas practice exercises
- `Lookup Table`: short reference notes for common data structures and algorithms
- `quest`: older exercises and topic-based practice that do not yet follow the main archive format

## Current Status

The repository is being normalized toward a single structure for all problems under `Easy`, `Medium`, and `Hard`.

The intended standard for each problem directory is:

- `metadata.json` with searchable structured metadata
- `README.md` with the problem statement, approach, and complexity notes
- one or more language-specific implementations

Some problems already follow this format, while others still need metadata and per-problem documentation.

## Repository Tooling

The `scripts` folder contains lightweight maintenance tools:

- `python scripts/validate_repo.py`: validate the expected structure for the main archive
- `python scripts/generate_readme.py`: generate `PROBLEMS.md` from available metadata
- `python scripts/stats.py`: print aggregate repository statistics from metadata

## Review Notes

This repository is currently being prepared for review in small, quality-focused passes.

In this first pass, the repo-level structure and conventions are being cleaned up before backfilling every problem directory.

## Next Milestones

- bring every `Easy` / `Medium` / `Hard` problem up to the standard structure
- generate and keep `PROBLEMS.md` in sync with metadata
- keep validation green in CI
