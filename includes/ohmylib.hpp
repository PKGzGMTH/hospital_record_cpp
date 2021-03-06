#ifndef OHMYLIB_HPP
# define OHMYLIB_HPP
# include <iostream>
# include <fstream>
# include <string>
# include <cstring>
# include <ctime>

#ifdef _WIN32
# define clear()	system("cls")
#else
# define clear()	system("clear")
#endif

using namespace std;

class display
{
	public:
		void	show_logo(void);
		void	admin_menu(void);
		void	patient_menu(void);
		void	header(string str);
		int		select_main_menu(void);
};

class	records: public display
{
	public:
		string	user = "";
		string	data = "";
		string	date = "";
		string	fullname = "";

	public:
		int	login(void);
		int	login(string pass);
		int	show_records(void);
		int	show_records(string username);
};

class	patient: public records
{
	public:
		string	*patient_name = &fullname;
};

class	admin: public records
{
	public:
		string	patient_name;
		string	password;

	public:
		void	add_records(void);
		int		remove_records(void);
};

int		check_name(string text);
string	get_date(void);
string	color(string str, unsigned char color);

#endif
