from __future__ import annotations

import json
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
DIFFICULTIES = ["Easy", "Medium", "Hard"]


def load_metadata():
    items = []
    for path in ROOT.rglob("metadata.json"):
        try:
            data = json.loads(path.read_text(encoding="utf-8"))
            data["_path"] = str(path.relative_to(ROOT))
            items.append(data)
        except Exception as e:
            print(f"Skipping {path}: {e}")
    return items


def main():
    items = load_metadata()
    if not items:
        print("No metadata.json files found.")
        return

    by_difficulty = Counter()
    by_language = Counter()
    by_topic = Counter()
    multi_lang = Counter()

    for item in items:
        difficulty = item.get("difficulty", "Unknown")
        languages = item.get("languages", [])
        topics = item.get("topics", [])

        by_difficulty[difficulty] += 1

        for lang in languages:
            by_language[lang] += 1

        for topic in topics:
            by_topic[topic] += 1

        multi_lang[len(languages)] += 1

    print("=== Problems by difficulty ===")
    for diff, count in sorted(by_difficulty.items()):
        print(f"{diff}: {count}")

    print("\n=== Problems by language ===")
    for lang, count in sorted(by_language.items()):
        print(f"{lang}: {count}")

    print("\n=== Top topics ===")
    for topic, count in by_topic.most_common(15):
        print(f"{topic}: {count}")

    print("\n=== Multi-language coverage ===")
    for n, count in sorted(multi_lang.items()):
        print(f"{n} language(s): {count} problem(s)")


if __name__ == "__main__":
    main()