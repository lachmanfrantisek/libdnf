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


#ifndef LIBDNF_CLI_PROGRESSBAR_WIDGETS_WIDGET_HPP
#define LIBDNF_CLI_PROGRESSBAR_WIDGETS_WIDGET_HPP


#include <string>


namespace libdnf::cli::progressbar {


class ProgressBar;


class Widget {
public:
    bool get_visible() const { return visible; }
    void set_visible(bool value) { visible = value; };

    ProgressBar * get_bar() const { return bar; }
    void set_bar(ProgressBar * value) { bar = value; }

    virtual std::size_t get_total_width() = 0;
    virtual std::string to_string() = 0;

    std::string get_delimiter_before() const { return delimiter_before; }
    void set_delimiter_before(const std::string & value) { delimiter_before = value; }

private:
    ProgressBar * bar = nullptr;
    bool visible{true};
    std::string delimiter_before;
};


}  // namespace libdnf::cli::progressbar


#endif  // LIBDNF_CLI_PROGRESSBAR_WIDGETS_WIDGET_HPP
