#pragma once

namespace reflect {
template <typename T>
class Singleton {
public:
    static T* instance() {
        static T* t = new T();
        return t;
    }
};
}  // namespace singleton
