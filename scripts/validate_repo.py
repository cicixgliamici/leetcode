from __future__ import annotations

import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def main():
    errors = []

    for diff_dir in ["Easy", "Medium", "Hard"]:
        base = ROOT / diff_dir
        if not base.exists():
            continue

        for problem_dir in base.iterdir():
            if not problem_dir.is_dir():
                continue

            metadata = problem_dir / "metadata.json"
            readme = problem_dir / "README.md"

            if not metadata.exists():
                errors.append(f"Missing metadata.json in {problem_dir}")
            if not readme.exists():
                errors.append(f"Missing README.md in {problem_dir}")

            if metadata.exists():
                try:
                    data = json.loads(metadata.read_text(encoding="utf-8"))
                    for key in ["id", "title", "difficulty", "topics", "languages", "status"]:
                        if key not in data:
                            errors.append(f"Missing '{key}' in {metadata}")
                except Exception as e:
                    errors.append(f"Invalid JSON in {metadata}: {e}")

    if errors:
        print("Repository issues found:\n")
        for err in errors:
            print(f"- {err}")
        sys.exit(1)
    else:
        print("Repository structure is valid.")


if __name__ == "__main__":
    main()
