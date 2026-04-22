# Contributing

This repository is primarily a personal LeetCode archive, but contributions and cleanup passes should follow a consistent structure.

## Main Archive Convention

Problems in `Easy`, `Medium`, and `Hard` should use this layout:

- `metadata.json`
- `README.md`
- one or more language folders or solution files

Recommended metadata keys:

- `id`
- `title`
- `slug`
- `difficulty`
- `topics`
- `source`
- `status`
- `languages`
- `implementation_counts`

## Documentation Expectations

Per-problem `README.md` files should usually include:

- problem summary
- example input and output
- explanation of the chosen approach
- time and space complexity

## Naming

- use lowercase kebab-case directory names for problem folders
- keep language names stable across metadata and paths
- prefer clear, descriptive filenames over abbreviations when practical

## Validation

Before opening a review-ready change, run:

```powershell
python scripts\validate_repo.py
python scripts\stats.py
```

If a change updates problem metadata coverage, also regenerate the root index:

```powershell
python scripts\generate_readme.py
```
