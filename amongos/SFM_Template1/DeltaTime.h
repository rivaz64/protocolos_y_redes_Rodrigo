#pragma once
namespace gl {
	class DeltaTime
	{
	public:
		static float Time() { return m_time; }
	private:
		friend class Game;
		static float m_time;
	};
}
