#pragma once
using std::string;
using std::cin;
using std::cout;
using std::endl;





// void Window_mgr::clear(ScreenIndex);
//class Window_mgr;

//class Screen;




class Screen {
	friend class Window_mgr;
//	friend void Window_mgr::clear(ScreenIndex);

public:
	typedef std::string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht *wd, c) {}
	char get() const
	{
		return contents[cursor];
	}
	inline char get(pos ht, pos wd) const;
	Screen &move(pos r, pos c);

	Screen &set(char);
	Screen &set(pos, pos, char);


	Screen &display(std::ostream &os)
	{
		do_display(os);
		return *this;
	}
	const Screen &display(std::ostream &os) const
	{
		do_display(os);
		return *this;

	}

	pos size() const;

	


private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
	void do_display(std::ostream &os) const { os << contents; }
};


class Window_mgr {
	friend class Screen;
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex);
	Screen &get(ScreenIndex i)
	{
		return screens[i];
	}
private:
	std::vector<Screen> screens{ Screen(24,80,'z') };
};



//成员函数定义
inline Screen &Screen::move(pos r, pos c)
{
	pos row = r*width;
	cursor = row + c;
	return *this;
}

char Screen::get(pos r, pos c) const
{
	pos row = r * width;
	return contents[row + c];
}

inline Screen &Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
	contents[r * width + col] = ch;
	return *this;
}


Screen::pos Screen::size() const
	{
		return height * width;
	}

void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = screens[i];
	s.contents = string(s.height * s.width, ' ');
}