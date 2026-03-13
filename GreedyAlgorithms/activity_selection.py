"""
Activity selection (greedy by finish time).
"""

def select_activities(activities):
    activities = sorted(activities, key=lambda x: x[1])
    selected = []
    last_end = None

    for start, end in activities:
        if last_end is None or start >= last_end:
            selected.append((start, end))
            last_end = end

    return selected


if __name__ == "__main__":
    activities = [(1, 4), (3, 5), (0, 6), (5, 7), (3, 8), (5, 9), (6, 10), (8, 11), (8, 12), (2, 13), (12, 14)]
    result = select_activities(activities)
    print("Selected activities:")
    print(result)
