/*
Part of Newcastle University's Game Engineering source code.

Use as you see fit!

Comments and queries to: richard-gordon.davison AT ncl.ac.uk
https://research.ncl.ac.uk/game/
*/
#pragma once

namespace NCL::Maths {
	class Vector3i;
	class Vector4i;
	class Vector2i {
	public:
		union {
			struct {
				int x;
				int y;
			};
			int array[2];
		};

	public:
		constexpr Vector2i(void) : x(0), y(0) {}

		constexpr Vector2i(int xVal, int yVal) : x(xVal), y(yVal) {}

		Vector2i(const Vector3i& v3);
		Vector2i(const Vector4i& v4);

		~Vector2i(void) = default;

		constexpr int		GetMaxElement() const {
			int v = x;
			if (y > v) {
				v = y;
			}
			return v;
		}

		int		GetAbsMaxElement() const {
			int ax = abs(x);
			int ay = abs(y);

			if (ax > ay) {
				return ax;
			}
			return ay;
		}

		static constexpr Vector2i Clamp(const Vector2i& input, const Vector2i& mins, const Vector2i& maxs);

		inline Vector2i  operator+(const Vector2i& a) const {
			return Vector2i(x + a.x, y + a.y);
		}

		inline Vector2i  operator-(const Vector2i& a) const {
			return Vector2i(x - a.x, y - a.y);
		}

		inline Vector2i  operator-() const {
			return Vector2i(-x, -y);
		}

		inline Vector2i  operator*(int a)	const {
			return Vector2i(x * a, y * a);
		}

		inline Vector2i  operator*(const Vector2i& a) const {
			return Vector2i(x * a.x, y * a.y);
		}

		inline Vector2i  operator/(const Vector2i& a) const {
			return Vector2i(x / a.x, y / a.y);
		};

		inline Vector2i  operator/(float v) const {
			return Vector2i(x / v, y / v);
		};

		inline constexpr void operator+=(const Vector2i& a) {
			x += a.x;
			y += a.y;
		}

		inline void operator-=(const Vector2i& a) {
			x -= a.x;
			y -= a.y;
		}

		inline void operator*=(const Vector2i& a) {
			x *= a.x;
			y *= a.y;
		}

		inline void operator/=(const Vector2i& a) {
			x /= a.x;
			y /= a.y;
		}

		inline void operator*=(float f) {
			x *= f;
			y *= f;
		}

		inline void operator/=(float f) {
			x /= f;
			y /= f;
		}

		inline constexpr float operator[](int i) const {
			return array[i];
		}

		inline constexpr int& operator[](int i) {
			return array[i];
		}

		inline bool	operator==(const Vector2i& A)const { return (A.x == x && A.y == y) ? true : false; };
		inline bool	operator!=(const Vector2i& A)const { return (A.x == x && A.y == y) ? false : true; };

		inline friend std::ostream& operator<<(std::ostream& o, const Vector2i& v) {
			o << "Vector2i(" << v.x << "," << v.y << ")\n";
			return o;
		}
	};
}