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


#include "libdnf-cli/progressbar/progress_bar.hpp"
#include "libdnf-cli/progressbar/widgets/percent.hpp"

#include <cmath>
#include <iomanip>
#include <sstream>


namespace libdnf::cli::progressbar {


std::size_t PercentWidget::get_total_width() {
    return 4 + get_delimiter_before().size();
}


std::string PercentWidget::to_string() {
    if (!get_visible()) {
        return "";
    }

    std::ostringstream ss;
    ss << get_delimiter_before();
    if (get_bar()->get_percent_done() >= 0) {
        ss << std::right << std::setw(3) << get_bar()->get_percent_done();
    } else {
        ss << std::right << std::setw(3) << "???";
    }
    ss << "%";
    return ss.str();
}


}  // namespace libdnf::cli::progressbar
