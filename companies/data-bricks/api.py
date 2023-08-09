# write a function get user ids from url get all user id and for each of them get details from antoher url and merge ithem into single dataframe with column as id,name ,surname,role using r


import requests
import pandas as pd
BASE_URL = "http://codility-task-api.com"
def get_data_from_api():
    user_ids = requests.get(BASE_URL + "/users").json()
    ret = pd.DataFrame(
        columns=["id", "name", "surname", "role"]
        ignore_index=True
    )
    for user_id in user_ids:
        id, name, surname, role = requests.get(BASE_URL + "/users/" + user_id).json()
        # add new row to ret
        ret = ret.append(
            {"id": id, "name": name, "surname": surname, "role": role},
            ignore_index=True
        )
        
    return ret
 