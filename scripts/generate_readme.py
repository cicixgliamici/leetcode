from __future__ import annotations

import json
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
README_PATH = ROOT / "README.md"


def load_metadata():
    items = []
    for path in ROOT.rglob("metadata.json"):
        try:
            data = json.loads(path.read_text(encoding="utf-8"))
            data["_dir"] = path.parent
            items.append(data)
        except Exception as e:
            print(f"Skipping {path}: {e}")
    return items


def make_problem_link(item):
    rel = item["_dir"].relative_to(ROOT).as_posix()
    return f"- [{item['id']}. {item['title']}]({rel})"


def build_readme(items):
    by_difficulty = defaultdict(list)
    by_language = Counter()

    for item in items:
        by_difficulty[item.get("difficulty", "Unknown")].append(item)
        for lang in item.get("languages", []):
            by_language[lang] += 1

    total = len(items)

    lines = []
    lines.append("# LeetCode 💻🚀")
    lines.append("")
    lines.append("This repository contains my LeetCode solutions in multiple programming languages.")
    lines.append("")
    lines.append("## Progress")
    lines.append("")
    lines.append("| Difficulty | Count |")
    lines.append("|---|---:|")
    for diff in ["Easy", "Medium", "Hard"]:
        lines.append(f"| {diff} | {len(by_difficulty.get(diff, []))} |")
    lines.append(f"| Total | {total} |")
    lines.append("")
    lines.append("## Languages")
    lines.append("")
    lines.append("| Language | Problems |")
    lines.append("|---|---:|")
    for lang, count in sorted(by_language.items()):
        lines.append(f"| {lang} | {count} |")

    for diff in ["Easy", "Medium", "Hard"]:
        problems = sorted(by_difficulty.get(diff, []), key=lambda x: x["id"])
        lines.append("")
        lines.append(f"## {diff}")
        lines.append("")
        for p in problems:
            lines.append(make_problem_link(p))

    return "\n".join(lines) + "\n"


def main():
    items = load_metadata()
    content = build_readme(items)
    README_PATH.write_text(content, encoding="utf-8")
    print("README generated.")


if __name__ == "__main__":
    main()