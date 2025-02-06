import requests
import os

CONTEST = "arc107"
PROBLEM = "C"

def download_data(name,in_url, out_url, save_dir):

    in_content = requests.get(in_url).text
    out_content = requests.get(out_url).text
    if len(in_content) == 0 or len(out_content) == 0:
        return
    with open(os.path.join(save_dir,f"{name}.in"), "w") as f:
        f.write(in_content)
    with open(os.path.join(save_dir,f"{name}.out"), "w") as f:
        f.write(out_content)

def get_files(contest, problem):
    url = f"https://api.github.com/repos/conlacda/atcoder-testcases/contents/{contest}/{problem}/in?ref={contest}"
    response = requests.get(url)
    in_files = response.json()
    
    url = f"https://api.github.com/repos/conlacda/atcoder-testcases/contents/{contest}/{problem}/out?ref={contest}"
    response = requests.get(url)
    out_files = response.json()
    return in_files, out_files
    
def main(contest=CONTEST, problem=PROBLEM):
    save_dir = f"{CONTEST}_{PROBLEM}"
    os.makedirs(save_dir, exist_ok=True)
    in_files,out_files = get_files(contest, problem)
    for in_file, out_file in zip(in_files, out_files):
        name = in_file["name"]
        in_download_url = in_file["download_url"]
        out_download_url = out_file["download_url"]
        download_data(name, in_download_url, out_download_url, save_dir)
    
if __name__ == "__main__":
    main()
