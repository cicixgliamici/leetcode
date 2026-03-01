import pandas as pd

def createDataframe(student_data: list[list[int]]) -> pd.DataFrame:
    """
    LeetCode 2877 - Create a DataFrame from List

    student_data is a 2D list like:
        [[1, 15],
         [2, 11],
         [3, 13]]

    We must return a pandas DataFrame with columns:
        student_id, age
    preserving the row order.
    """

    # In pandas, a DataFrame is a 2D table-like structure (like an Excel sheet):
    # - rows = records
    # - columns = named fields
    #
    # If you pass a "list of lists" to pd.DataFrame(...), pandas interprets:
    # - each inner list as a row
    # - each element inside that inner list as a column value

    # We specify the column names explicitly using the 'columns' parameter.
    # This ensures:
    # - the first value of each row becomes "student_id"
    # - the second value of each row becomes "age"
    df = pd.DataFrame(student_data, columns=["student_id", "age"])

    # Return the DataFrame (this is what LeetCode expects).
    return df
