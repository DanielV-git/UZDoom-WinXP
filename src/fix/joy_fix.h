#pragma once

// KEINE INCLUDES HIER!

struct _XpJoyCast {
	int _val;

	constexpr _XpJoyCast(float _f) noexcept : _val((int)_f) {}
	constexpr _XpJoyCast(int _i) noexcept : _val(_i) {}

	constexpr operator EJoyCurve() const noexcept {
		return (EJoyCurve)_val;
	}
};

#define EJoyCurve _XpJoyCast
