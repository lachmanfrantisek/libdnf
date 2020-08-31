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
#include "libdnf-cli/progressbar/widgets/speed.hpp"


namespace libdnf::cli::progressbar {


std::size_t SpeedWidget::get_total_width() {
    return 10 + get_delimiter_before().size();
}


std::string SpeedWidget::to_string() {
    if (!get_visible()) {
        return "";
    }
    if (get_bar()->is_finished() || get_bar()->get_total_ticks() < 0) {
        // finshed -> display average speed
        return get_delimiter_before() + format_size(get_bar()->get_average_speed()) + "/s";
    } else {
        // in progress -> display current speed
        return get_delimiter_before() + format_size(get_bar()->get_average_speed()) + "/s";
    }
}


}  // namespace libdnf::cli::progressbar
