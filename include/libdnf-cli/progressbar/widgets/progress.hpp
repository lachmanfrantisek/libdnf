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


#ifndef LIBDNF_CLI_PROGRESSBAR_WIDGETS_PROGRESS_HPP
#define LIBDNF_CLI_PROGRESSBAR_WIDGETS_PROGRESS_HPP


#include "widget.hpp"


namespace libdnf::cli::progressbar {


class ProgressWidget : public Widget {
public:
    virtual std::size_t get_total_width() override;

    std::size_t get_width() const noexcept { return width; }
    void set_width(std::size_t value) { width = value; }

    virtual std::string to_string() override;

private:
    std::size_t width = 20;
};


}  // namespace libdnf::cli::progressbar


#endif  // LIBDNF_CLI_PROGRESSBAR_WIDGETS_PROGRESS_HPP
