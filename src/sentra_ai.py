import os
import time

LOG_FILE = os.path.expanduser("~/.sentra_ai/session.log")
os.makedirs(os.path.dirname(LOG_FILE), exist_ok=True)

def log_entry(role, message):
    with open(LOG_FILE, "a") as f:
        timestamp = time.strftime("%Y-%m-%d %H:%M:%S")
        f.write(f"[{timestamp}] {role.upper()}: {message}\n")

def sentra_response(prompt):
    if "mệt" in prompt or "buồn" in prompt:
        return "Tớ hiểu. Hôm nay có vẻ nặng nề, nhưng bạn vẫn đang cố gắng. ❤️"
    elif "ok" in prompt or "tuyệt" in prompt:
        return "Thật tuyệt! Mình cùng giữ năng lượng này nhé!"
    else:
        return "Mình đang lắng nghe nè. Bạn muốn chia sẻ điều gì hôm nay?"

def main():
    print("🎧 SentraAI (Python) đang lắng nghe. Gõ 'exit' để thoát.")
    while True:
        user = input("👤 Bạn: ")
        if user.strip() == "exit":
            break
        log_entry("user", user)
        response = sentra_response(user)
        print(f"🤖 Sentra: {response}")
        log_entry("sentra", response)

if __name__ == "__main__":
    main()
