/*
	Copyright (C) 2014 - 2025
	by Chris Beck <render787@gmail.com>
	Part of the Battle for Wesnoth Project https://www.wesnoth.org/

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.
	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY.

	See the COPYING file for more details.
*/

/**
 *
 * This wrapper class should be held by the display object when it needs to draw a unit.
 * The purpose of this is to improve encapsulation -- other parts of the engine like AI
 * don't need to be exposed to the unit drawing code, and encapsulation like this will
 * help us to reduce unnecessary includes.
 *
 **/

#pragma once

#include "map/location.hpp"

#include <vector>

class display;
class display_context;
struct frame_parameters;
class gamemap;
namespace halo { class manager; }
class team;
class unit;


class unit_drawer
{
public:
	explicit unit_drawer(display & thedisp);

private:
	display & disp;
	const display_context & dc;
	const gamemap & map;
	halo::manager & halo_man;
	const team & viewing_team_ref;
	const team & playing_team_ref;
	bool is_blindfolded;
	bool show_everything;
	map_location sel_hex;
	map_location mouse_hex;
	double zoom_factor;
	std::set<map_location> units_that_can_reach_goal;

	int hex_size;
	int hex_size_by_2;

	/** @todo: better name... unclear what the reachable part actually means */
	bool selected_or_reachable(const map_location& loc) const;

	void draw_ellipses(const unit& u, const frame_parameters& params) const;

public:
	/** draw a unit.  */
	void redraw_unit(const unit & u) const;
};
