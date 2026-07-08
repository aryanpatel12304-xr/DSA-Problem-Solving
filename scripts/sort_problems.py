import os
import re
import shutil
from urllib.parse import quote

# Repository ka main/root folder
ROOT = os.path.dirname(
    os.path.dirname(os.path.abspath(__file__))
)

MAIN_README = os.path.join(ROOT, "README.md")


# Agar ek problem multiple topics me ho,
# to is priority ke according main topic choose hoga.
TOPIC_PRIORITY = [
    "Array",
    "String",
    "Hash Table",
    "Binary Search",
    "Linked List",
    "Stack",
    "Queue",
    "Tree",
    "Binary Tree",
    "Binary Search Tree",
    "Heap (Priority Queue)",
    "Graph",
    "Backtracking",
    "Greedy",
    "Dynamic Programming",
    "Two Pointers",
    "Sliding Window",
    "Divide and Conquer",
    "Math",
    "Bit Manipulation",
]


# LeetCode topic -> hamara clean folder name
TOPIC_FOLDER_NAMES = {
    "Array": "01-Arrays",
    "String": "02-Strings",
    "Hash Table": "03-Hashing",
    "Binary Search": "04-Binary-Search",
    "Linked List": "05-Linked-List",
    "Stack": "06-Stack",
    "Queue": "07-Queue",
    "Tree": "08-Trees",
    "Binary Tree": "08-Trees",
    "Binary Search Tree": "08-Trees",
    "Heap (Priority Queue)": "09-Heaps",
    "Graph": "10-Graphs",
    "Backtracking": "11-Backtracking",
    "Greedy": "12-Greedy",
    "Dynamic Programming": "13-Dynamic-Programming",
    "Two Pointers": "14-Two-Pointers",
    "Sliding Window": "15-Sliding-Window",
    "Divide and Conquer": "16-Divide-and-Conquer",
    "Math": "17-Math",
    "Bit Manipulation": "18-Bit-Manipulation",
}


def read_main_readme():
    """
    Main README.md ko read karta hai.
    """

    if not os.path.exists(MAIN_README):
        print("ERROR: Main README.md nahi mila.")
        return ""

    with open(
        MAIN_README,
        "r",
        encoding="utf-8"
    ) as file:
        return file.read()


def write_main_readme(content):
    """
    Updated README.md ko save karta hai.
    """

    with open(
        MAIN_README,
        "w",
        encoding="utf-8"
    ) as file:
        file.write(content)


def build_problem_topic_map(readme_content):
    """
    Main README se:
    problem -> topics
    mapping banata hai.
    """

    problem_topics = {}
    current_topic = None

    for line in readme_content.splitlines():

        if line.startswith("## "):
            current_topic = line[3:].strip()
            continue

        match = re.search(
            r"\[([0-9]{4}-[a-z0-9-]+)\]",
            line,
            re.IGNORECASE
        )

        if match and current_topic:

            problem_name = match.group(1)

            if problem_name not in problem_topics:
                problem_topics[problem_name] = []

            if current_topic not in problem_topics[problem_name]:
                problem_topics[problem_name].append(
                    current_topic
                )

    return problem_topics


def choose_main_topic(topics):
    """
    Multiple topics me se ek main topic
    priority ke according choose karta hai.
    """

    for preferred_topic in TOPIC_PRIORITY:

        if preferred_topic in topics:
            return preferred_topic

    if topics:
        return topics[0]

    return "Other"


def get_difficulty(problem_folder_path):
    """
    Problem ke README.md se:
    Easy / Medium / Hard
    detect karta hai.
    """

    readme_path = os.path.join(
        problem_folder_path,
        "README.md"
    )

    if not os.path.exists(readme_path):
        return "Unknown"

    with open(
        readme_path,
        "r",
        encoding="utf-8"
    ) as file:
        content = file.read()

    match = re.search(
        r"<h3>\s*(Easy|Medium|Hard)\s*</h3>",
        content,
        re.IGNORECASE
    )

    if match:
        return match.group(1).capitalize()

    return "Unknown"


def is_problem_folder(folder_name):
    """
    Sirf actual LeetCode problem folders detect karega.
    """

    return bool(
        re.fullmatch(
            r"\d{4}-[a-z0-9][a-z0-9-]*",
            folder_name,
            re.IGNORECASE
        )
    )


def find_all_problem_locations():
    """
    Repo ke andar recursively saare actual
    problem folders find karta hai.

    Return:
    problem_name -> relative path
    """

    problem_locations = {}

    for current_root, dirs, files in os.walk(ROOT):

        # Git internals scan mat karo
        dirs[:] = [
            directory
            for directory in dirs
            if directory != ".git"
        ]

        current_folder_name = os.path.basename(
            current_root
        )

        if not is_problem_folder(current_folder_name):
            continue

        relative_path = os.path.relpath(
            current_root,
            ROOT
        )

        # Windows backslash ko GitHub slash me badlo
        relative_path = relative_path.replace(
            os.sep,
            "/"
        )

        problem_locations[
            current_folder_name
        ] = relative_path

        # Problem folder ke andar aur scan ki zarurat nahi
        dirs[:] = []

    return problem_locations


def update_readme_links(
    readme_content,
    problem_locations
):
    """
    README ke problem links ko actual
    current folder path ke according repair karta hai.
    """

    updated_count = 0

    pattern = re.compile(
        r"(\[([0-9]{4}-[a-z0-9-]+)\]\()"
        r"(https://github\.com/[^)\s]+)"
        r"(\))",
        re.IGNORECASE
    )

    def replace_link(match):
        nonlocal updated_count

        prefix = match.group(1)
        problem_name = match.group(2)
        old_url = match.group(3)
        suffix = match.group(4)

        actual_path = problem_locations.get(
            problem_name
        )

        if not actual_path:
            return match.group(0)

        # Existing URL se repo base nikalo
        base_match = re.match(
            r"(https://github\.com/[^/]+/[^/]+)"
            r"/tree/[^/]+/",
            old_url,
            re.IGNORECASE
        )

        if not base_match:
            return match.group(0)

        repo_base = base_match.group(1)

        # Path safely encode karo
        encoded_path = quote(
            actual_path,
            safe="/-._~"
        )

        new_url = (
            f"{repo_base}/tree/main/"
            f"{encoded_path}/"
        )

        if new_url != old_url:
            updated_count += 1

        return (
            f"{prefix}"
            f"{new_url}"
            f"{suffix}"
        )

    updated_content = pattern.sub(
        replace_link,
        readme_content
    )

    return updated_content, updated_count


def main():

    readme_content = read_main_readme()

    if not readme_content:
        return

    problem_topic_map = build_problem_topic_map(
        readme_content
    )

    moved_count = 0

    # Root-level naye LeetHub problem folders sort karo
    for folder_name in os.listdir(ROOT):

        old_path = os.path.join(
            ROOT,
            folder_name
        )

        if not os.path.isdir(old_path):
            continue

        if not is_problem_folder(folder_name):
            continue

        topics = problem_topic_map.get(
            folder_name,
            []
        )

        main_topic = choose_main_topic(topics)

        difficulty = get_difficulty(old_path)

        topic_folder = TOPIC_FOLDER_NAMES.get(
            main_topic,
            "99-Other"
        )

        new_path = os.path.join(
            ROOT,
            topic_folder,
            difficulty,
            folder_name
        )

        os.makedirs(
            os.path.dirname(new_path),
            exist_ok=True
        )

        if os.path.exists(new_path):

            print(
                f"Skipped: {folder_name} "
                f"already exists at destination"
            )

            continue

        shutil.move(
            old_path,
            new_path
        )

        print(
            f"Moved: {folder_name} -> "
            f"{topic_folder}/{difficulty}/"
        )

        moved_count += 1

    # Move ke baad actual locations dobara find karo
    problem_locations = find_all_problem_locations()

    # Existing + new broken README links repair karo
    latest_readme_content = read_main_readme()

    updated_readme, updated_link_count = (
        update_readme_links(
            latest_readme_content,
            problem_locations
        )
    )

    if updated_readme != latest_readme_content:
        write_main_readme(updated_readme)

    print(
        f"\nSorting complete! "
        f"Moved {moved_count} problem(s)."
    )

    print(
        f"README links updated: "
        f"{updated_link_count}"
    )


if __name__ == "__main__":
    main()