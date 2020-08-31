/*
Copyright (C) 2020 Red Hat, Inc.

This file is part of libdnf: https://github.com/rpm-software-management/libdnf/

Libdnf is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

Libdnf is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with libdnf.  If not, see <https://www.gnu.org/licenses/>.
*/


#include "common.hpp"

#include "libdnf-cli/progressbar/progress_bar.hpp"
#include "libdnf-cli/progressbar/widgets/number.hpp"

#include <cmath>
#include <iomanip>
#include <sstream>


namespace libdnf::cli::progressbar {


std::size_t NumberWidget::get_total_width() {
    return 3 + (2 * get_number_width()) + get_delimiter_before().size();
}


std::size_t NumberWidget::get_number_width() const {
    std::size_t result = std::max(
        static_cast<std::size_t>(log10(get_bar()->get_number())),
        static_cast<std::size_t>(log10(get_bar()->get_total())));
    return result + 1;
}


std::string NumberWidget::to_string() {
    if (!get_visible()) {
        return "";
    }
    std::ostringstream ss;
    auto number_width = get_number_width();
    ss << get_delimiter_before();
    ss << "[";
    ss << std::setw(static_cast<int32_t>(number_width)) << get_bar()->get_number();
    ss << "/";
    ss << std::setw(static_cast<int32_t>(number_width)) << get_bar()->get_total();
    ss << "]";
    return ss.str();
}


}  // namespace libdnf::cli::progressbar
