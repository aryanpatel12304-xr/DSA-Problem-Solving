import os
import shutil

# Repo ka main folder
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

# Problem number -> Topic + Difficulty
PROBLEM_MAP = {
    "0053": ("01-Arrays", "Medium"),
    "0283": ("01-Arrays", "Easy"),
    "1752": ("01-Arrays", "Easy"),
}

for folder_name in os.listdir(ROOT):

    old_path = os.path.join(ROOT, folder_name)

    # Sirf folders check karo
    if not os.path.isdir(old_path):
        continue

    # Problem number nikalo
    problem_number = folder_name.split("-")[0]

    # Agar problem map me hai
    if problem_number in PROBLEM_MAP:

        topic, difficulty = PROBLEM_MAP[problem_number]

        new_path = os.path.join(
            ROOT,
            topic,
            difficulty,
            folder_name
        )

        # Destination folders banao
        os.makedirs(
            os.path.dirname(new_path),
            exist_ok=True
        )

        # Problem folder move karo
        shutil.move(old_path, new_path)

        print(
            f"Moved: {folder_name} -> "
            f"{topic}/{difficulty}/"
        )

print("Sorting complete!")