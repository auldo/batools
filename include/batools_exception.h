#pragma once

#include <stdexcept>
#include <string_view>

namespace batools {
    class batools_exception : public std::exception {
    private:
        std::string_view _message{""};
    public:
        batools_exception(std::string_view message) noexcept;
        const char * what() const noexcept override;
    };

    namespace exceptions {
        ::batools::batools_exception out_of_range();
    }
}