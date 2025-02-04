import requests

for i in range(2,46):
    in_url = "https://raw.githubusercontent.com/conlacda/atcoder-testcases/refs/heads/abc219/abc219/E/in/{:03d}".format(i)
    
    out_url = "https://raw.githubusercontent.com/conlacda/atcoder-testcases/refs/heads/abc219/abc219/E/out/{:03d}".format(i)
    in_content = requests.get(in_url).text
    out_content = requests.get(out_url).text
    if len(in_content) == 0 or len(out_content) == 0:
        continue
    with open("{:03d}.in".format(i), "w") as f:
        f.write(in_content)
    with open("{:03d}.out".format(i), "w") as f:
        f.write(out_content)