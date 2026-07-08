import os
import re
import shutil

# Repository ka main/root folder
ROOT = os.path.dirname(
    os.path.dirname(os.path.abspath(__file__))
)

# Main README.md ka path
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


def build_problem_topic_map(readme_content):
    """
    Main README se:
    problem -> topics
    mapping banata hai.
    """

    problem_topics = {}
    current_topic = None

    for line in readme_content.splitlines():

        # Topic heading detect karo
        # Example:
        # ## Array
        if line.startswith("## "):
            current_topic = line[3:].strip()
            continue

        # Problem detect karo
        # Example:
        # [0283-move-zeroes]
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

    Valid:
    0053-maximum-subarray
    0283-move-zeroes
    1752-check-if-array-is-sorted-and-rotated

    Invalid:
    01-Arrays
    02-Strings
    99-Other
    scripts
    incoming
    """

    return bool(
        re.fullmatch(
            r"\d{4}-[a-z0-9][a-z0-9-]*",
            folder_name,
            re.IGNORECASE
        )
    )


def main():

    readme_content = read_main_readme()

    if not readme_content:
        return

    problem_topic_map = build_problem_topic_map(
        readme_content
    )

    moved_count = 0

    # Root folder ke items check karo
    for folder_name in os.listdir(ROOT):

        old_path = os.path.join(
            ROOT,
            folder_name
        )

        # File hai to ignore
        if not os.path.isdir(old_path):
            continue

        # Actual problem folder nahi hai to ignore
        if not is_problem_folder(folder_name):
            continue

        # Problem ke topics nikalo
        topics = problem_topic_map.get(
            folder_name,
            []
        )

        # Main topic choose karo
        main_topic = choose_main_topic(topics)

        # Difficulty nikalo
        difficulty = get_difficulty(old_path)

        # Topic folder choose karo
        topic_folder = TOPIC_FOLDER_NAMES.get(
            main_topic,
            "99-Other"
        )

        # Final destination
        new_path = os.path.join(
            ROOT,
            topic_folder,
            difficulty,
            folder_name
        )

        # Destination parent folders banao
        os.makedirs(
            os.path.dirname(new_path),
            exist_ok=True
        )

        # Agar already destination me hai
        # to overwrite mat karo
        if os.path.exists(new_path):

            print(
                f"Skipped: {folder_name} "
                f"already exists at destination"
            )

            continue

        # Problem folder move karo
        shutil.move(
            old_path,
            new_path
        )

        print(
            f"Moved: {folder_name} -> "
            f"{topic_folder}/{difficulty}/"
        )

        moved_count += 1

    print(
        f"\nSorting complete! "
        f"Moved {moved_count} problem(s)."
    )


if __name__ == "__main__":
    main()