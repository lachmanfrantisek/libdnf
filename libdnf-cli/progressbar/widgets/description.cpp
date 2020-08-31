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
#include "libdnf-cli/progressbar/widgets/description.hpp"

#include <iomanip>


namespace libdnf::cli::progressbar {


std::size_t DescriptionWidget::get_total_width() {
    if (width > 0) {
        return width + get_delimiter_before().size();
    }
    return get_bar()->get_description().size() + get_delimiter_before().size();
}


void DescriptionWidget::set_total_width(std::size_t value) {
    set_width(value - get_delimiter_before().size());
}


std::string DescriptionWidget::to_string() {
    if (!get_visible()) {
        return "";
    }
    std::ostringstream ss;
    ss << get_delimiter_before();
    ss << std::left;
    ss << std::setw(static_cast<int>(get_total_width() - get_delimiter_before().size()));
    ss << get_bar()->get_description();
    return ss.str();
}


}  // namespace libdnf::cli::progressbar
