unique_lock vs lock_guard

https://stackoverflow.com/questions/20516773/stdunique-lockstdmutex-or-stdlock-guardstdmutex

> The difference is that you can lock and unlock a std::unique_lock. std::lock_guard will be locked only once on construction and unlocked on destruction.