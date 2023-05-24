import pandas as pd
import requests

res = requests.get(
    'https://coderbyte.com/api/challenges/json/age-counting'
).json()


data = res['data']
pt = data.split(", ")
cnt = 0
for i in range(0,len(pt),2):
    key,age = pt[i].split("=")[-1],pt[i+1].split("=")[-1]
    if(int(age)>=50): cnt +=1;
print(cnt)