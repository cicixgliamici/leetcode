import pandas as pd

def combine_two_tables(person: pd.DataFrame, address: pd.DataFrame) -> pd.DataFrame:
    # Merge all rows from person with matching rows from address
    result = person.merge(address, on="personId", how="left")
    
    # Select only the required columns
    return result[["firstName", "lastName", "city", "state"]]
