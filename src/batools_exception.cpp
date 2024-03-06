#include "batools_exception.h"

namespace batools {
    batools_exception::batools_exception(std::string_view message) noexcept : _message(message) {}

    const char *batools_exception::what() const noexcept {
        return _message.data();
    }

    namespace exceptions {
        ::batools::batools_exception out_of_range() {
            return {"Out of range."};
        }
    }
}