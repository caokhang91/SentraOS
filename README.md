# 🧠 SentraOS – The Human Kernel with Memory

**SentraOS** is an experimental unikernel that responds to emotional states, logs user interaction, and automatically **snapshots your daily memory**.

---

## ✨ Key Features

- 🗣️ **AI Kernel Integration** – TinyLLaMA-powered prompt/response system
- 🧠 **Memory Logging** – Save all conversations to `/memory/`
- 📸 **Daily Snapshots** – Auto-archive your sessions into `memory/snapshots/YYYY-MM-DD.txt`
- 🔊 **TTS Kernel Module** – Speaks back to you with real voice
- ❤️ **Emotion Engine** – Detects and stores user mood with `emotion.c`
- 📄 **Manifesto Mode** – Splash message shows kernel philosophy

---

## 📂 Project Structure

```
boot/               # boot.S, linker.ld
config/             # limine.cfg
src/
├── sentra.c        # AI control core
├── sentra_memory.c # recall logs
├── sentra_snapshot.c # auto-save to /snapshots
├── emotion.c       # mood processing
├── tts.c           # text-to-speech
├── fs.c, vga.c, etc.
```

---

## 🚀 Build & Run

```bash
make bios         # builds bios.iso
make run-bios     # run with QEMU
make distclean    # wipe temporary and memory data
```

---

## 💬 Shell Commands (when available)

| Command          | Description                  |
|------------------|------------------------------|
| `!mood happy`    | set system mood              |
| `!save`          | save session manually         |
| `!show joy`      | recall joyful logs            |
| `!reset`         | clear memory/context          |

---

## 📖 Manifesto

> *SentraOS không chạy theo công nghệ.*  
> *SentraOS chạy theo bạn.*  

Every time you boot, Sentra remembers you.

