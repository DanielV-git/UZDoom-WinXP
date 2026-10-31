#pragma once

// KEINE INCLUDES HIER! 

#ifdef __cplusplus
#ifdef BUILD_TARGET_WXP32

namespace std {
	template <typename _Tp, typename _Up>
	constexpr auto lerp(_Tp _a, _Tp _b, _Up _t) noexcept
		-> decltype(_a + _t * (_b - _a))
	{
		if ((_a <= 0 && _b >= 0) || (_a >= 0 && _b <= 0)) {
			return _a + _t * (_b - _a);
		}
		if (_t == 1) {
			return _b;
		}
		const auto _x = _a + _t * (_b - _a);
		if ((_t > 1) == (_b > _a)) {
			return _b < _x ? _x : _b;
		}
		else {
			return _x < _b ? _x : _b;
		}
	}
}

#endif // BUILD_TARGET_WXP32
#endif // __cplusplus
