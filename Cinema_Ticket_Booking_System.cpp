#include <iostream>
#include <string>
#define nmovies 4
using namespace std;
int globalTime = 620;

struct theater
{
	string theatre_id;
	int capacity;
	int reserved_seats;
};

struct Time {
	int hour[4];
	int minute[4];
};

struct screening_info
{
	theater theaterInformation;
	Time screeningTime;
};

struct movie
{
	string title;
	string director;
	string actors[5];
	double rating;
	screening_info movieTheaters[2];
}; movie film[nmovies];

void Display1();
void Display2();
void Display3();
void Display4();
int mainMenu();
void cash(int number_of_tickets);
void initializingMoviesTitlesDirectorsRating(movie film[nmovies]);
void initializingMoviesActors(movie film[nmovies]);
void initializingScreeningTheater(movie film[nmovies]);
void initializingScreeningTime(movie film[nmovies]);
void ticketsAvailability(int tickets, int movieNumber, int movieTheater);
movie addingMovie();
void listAvailableMovies();
void listTheatersShowingCertainMovieWithCertainTime();
void theatresShowingCertainMovies();
void listMoviesShowingAtCertainTime();
void comparingTime(int& time, int& movieNumber, int& movieTheater, int& screeningChoice);
void bookingTicket(int& movieNumber, int& movieTheater, int& numberOfTickets, int& screeningChoice);

int main()
{
	Display1();
	Display2();
	Display3();
	Display4();
	cout << endl;
	int x = 0, mainMenuCounter = 0;
	int movieNumber, movieTheater, numberOfTickets, screeningChoice;
	initializingMoviesActors(film);
	initializingMoviesTitlesDirectorsRating(film);
	initializingScreeningTheater(film);
	initializingScreeningTime(film);
	while (true)
	{
		x = mainMenu();
		switch (x) {
		case 1:
			listAvailableMovies();
			break;

		case 2:
			theatresShowingCertainMovies();
			break;

		case 3:
			listMoviesShowingAtCertainTime();
			break;

		case 4:
			bookingTicket(movieNumber, movieTheater, numberOfTickets, screeningChoice);
			break;

		case 5:
			exit(0);


		default:
			cout << "Wrong input, Program closed!" << endl;
			exit(0);
		}
	}
	return 0;
}
void Display1()
{
	for (int i = 0; i < 3; i++)
	{
		if (i == 0 || i == 2)
		{
			for (int j = 0; j < 135; j++)
			{
				cout << "^";
			}
			cout << endl;
		}
		else
		{
			for (int j = 0; j < 7; j++)
			{
				cout << "\t";
			}
			cout << "Ticket Booking System" << endl;
		}
	}
}
void Display2()
{
	for (int i = 0; i < 3; i++)
	{
		if (i == 0 || i == 2)
		{
			for (int j = 0; j < 135; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
		else
		{
			cout << "\t" << "\t" << "   *" << "\t" << "\t" << "      ";
			cout << "Theater 1";
			cout << "\t" << "\t" << "         *" << "\t" << "\t" << "  ";
			cout << "Theater 2";
			cout << "\t" << "\t" << "     " << "*";
			cout << endl;
		}
	}
}
void Display3()
{
	cout << "  Serial Number " << "   *    SHOW1  |  SHOW2  |  SHOW3  |  SHOW4   ";
	cout << "   *  SHOW5  |  SHOW6  |  SHOW7  |  SHOW8  ";
	cout << "    *       Movie Name";
	cout << endl;
	for (int i = 0; i < 135; i++)
	{
		cout << "*";
	}
	cout << endl;
}
void Display4()
{
	cout << "       (1)" << "\t" << "   *";
	cout << "    10:00  |  12:30  |  15:00  |  17:30  ";
	cout << "    *" << "  11:00  |  13:30  |  16:00  |  18:30  " << "    *";
	cout << "        Titanic" << endl;
	cout << endl;
	cout << "       (2)" << "\t" << "   *";
	cout << "    10:00  |  12:30  |  15:00  |  17:30  ";
	cout << "    *" << "  11:00  |  13:30  |  16:00  |  18:30  " << "    *";
	cout << "   Spider-Man No Way Home" << endl;
	cout << endl;
	cout << "       (3)" << "\t" << "   *";
	cout << "    10:00  |  12:30  |  15:00  |  17:30  ";
	cout << "    *" << "  11:00  |  13:30  |  16:00  |  18:30  " << "    *";
	cout << "      Finding Dory" << endl;
	cout << endl;
	cout << "       (4)" << "\t" << "   *";
	cout << "    10:00  |  12:30  |  15:00  |  17:30  ";
	cout << "    *" << "  11:00  |  13:30  |  16:00  |  18:30  " << "    *";
	cout << "      The Conjuring";
	cout << endl;
	for (int i = 0; i < 135; i++)
	{
		cout << "*";
	}
	cout << endl;
}
int mainMenu()
{
	int x;
	cout << "Press 1 to view details of the movies" << endl;
	cout << "Press 2 to list theaters showing certain movie with its screening time" << endl;
	cout << "Press 3 to list all movies showing at certain time" << endl;
	cout << "Press 4 to book tickets" << endl;
	cout << "Press 5 to exit" << endl;
	cin >> x;
	return x;
}
void cash(int number_of_tickets) {
	int money;
	int i = 0;

	cout << "Price of single seat(100 L.E.)" << endl;

	cout << "THE PRICE OF YOUR TICKETS IS:" << number_of_tickets * 100 << endl;
	do {
		cout << "Enter Cash: ";
		cin >> money;
		if (money < number_of_tickets * 100) {
			cout << "Sorry! Your Cash Is Insufficient" << endl;
			cout << "PLEASE TRY AGAIN" << endl;
			i++;
		}
		else if (money > number_of_tickets * 100) {
			cout << "The change is:" << money - number_of_tickets * 100 << endl;
			cout << "THANK YOU!" << endl;
		}
		else
			cout << "THANK YOU!" << endl;
		cout << endl;
	} while (money < number_of_tickets * 100 && i < 3);
}
void initializingMoviesTitlesDirectorsRating(movie film[nmovies])
{
	film[0].title = "Titanic";
	film[1].title = "Spider-Man: No Way Home";
	film[2].title = "Finding Dory";
	film[3].title = "The Conjuring";

	film[0].director = "James Cameron";
	film[1].director = "Jon Watts";
	film[2].director = "Andrew Stanton";
	film[3].director = "Michael Chaves";

	film[0].rating = 7.9;
	film[1].rating = 8.4;
	film[2].rating = 7.3;
	film[3].rating = 6.3;
}
void initializingMoviesActors(movie film[nmovies])
{
	film[0].actors[0] = "Leonardo DiCaprio";
	film[0].actors[1] = "Kate Winslet";
	film[0].actors[2] = "Gloria Stuart";
	film[0].actors[3] = "Billy Zane";
	film[0].actors[4] = "Frances Fisher";

	film[1].actors[0] = "Tom Holland";
	film[1].actors[1] = "Zendaya";
	film[1].actors[2] = "Tobey Maguire";
	film[1].actors[3] = "Andrew Garfield";
	film[1].actors[4] = "Marisa Tomei";

	film[2].actors[0] = "Andrew Stanton";
	film[2].actors[1] = "Ellen DeGeneres";
	film[2].actors[2] = "Kaitlin Olson";
	film[2].actors[3] = "Hayden Rolence";
	film[2].actors[4] = "Alexander Gould";

	film[3].actors[0] = "Patrick Wilson";
	film[3].actors[1] = "Sarah Catherine";
	film[3].actors[2] = "Vera Farmiga";
	film[3].actors[3] = "Julian Hiliard";
	film[3].actors[4] = "Sterling Jerins";

}
void initializingScreeningTheater(movie film[nmovies])
{
	film[0].movieTheaters[0].theaterInformation.capacity = 75;
	film[0].movieTheaters[0].theaterInformation.reserved_seats = (rand() % 76);
	film[0].movieTheaters[0].theaterInformation.theatre_id = "Theater 1 Hall 1";

	film[0].movieTheaters[1].theaterInformation.capacity = 100;
	film[0].movieTheaters[1].theaterInformation.reserved_seats = (rand() % 101);
	film[0].movieTheaters[1].theaterInformation.theatre_id = "Theater 2 Hall 1";

	film[1].movieTheaters[0].theaterInformation.capacity = 75;
	film[1].movieTheaters[0].theaterInformation.reserved_seats = (rand() % 76);
	film[1].movieTheaters[0].theaterInformation.theatre_id = "Theater 1 Hall 2";

	film[1].movieTheaters[1].theaterInformation.capacity = 100;
	film[1].movieTheaters[1].theaterInformation.reserved_seats = (rand() % 101);
	film[1].movieTheaters[1].theaterInformation.theatre_id = "Theater 2 Hall 2";

	film[2].movieTheaters[0].theaterInformation.capacity = 75;
	film[2].movieTheaters[0].theaterInformation.reserved_seats = (rand() % 76);
	film[2].movieTheaters[0].theaterInformation.theatre_id = "Theater 1 Hall 3";

	film[2].movieTheaters[1].theaterInformation.capacity = 100;
	film[2].movieTheaters[1].theaterInformation.reserved_seats = (rand() % 101);
	film[2].movieTheaters[1].theaterInformation.theatre_id = "Theater 2 Hall 3";

	film[3].movieTheaters[0].theaterInformation.capacity = 75;
	film[3].movieTheaters[0].theaterInformation.reserved_seats = (rand() % (76));
	film[3].movieTheaters[0].theaterInformation.theatre_id = "Theater 1 Hall 4";

	film[3].movieTheaters[1].theaterInformation.capacity = 100;
	film[3].movieTheaters[1].theaterInformation.reserved_seats = (rand() % (101));
	film[3].movieTheaters[1].theaterInformation.theatre_id = "Theater 2 Hall 4";
}
void initializingScreeningTime(movie film[nmovies])
{
	//Film 1 Theater 1 Timings
	film[0].movieTheaters[0].screeningTime.hour[0] = 10;
	film[0].movieTheaters[0].screeningTime.minute[0] = 00;

	film[0].movieTheaters[0].screeningTime.hour[1] = 12;
	film[0].movieTheaters[0].screeningTime.minute[1] = 30;

	film[0].movieTheaters[0].screeningTime.hour[2] = 15;
	film[0].movieTheaters[0].screeningTime.minute[2] = 00;

	film[0].movieTheaters[0].screeningTime.hour[3] = 17;
	film[0].movieTheaters[0].screeningTime.minute[3] = 30;
	//Film 1 Theater 2 Timings
	film[0].movieTheaters[1].screeningTime.hour[0] = 11;
	film[0].movieTheaters[1].screeningTime.minute[0] = 00;

	film[0].movieTheaters[1].screeningTime.hour[1] = 13;
	film[0].movieTheaters[1].screeningTime.minute[1] = 30;

	film[0].movieTheaters[1].screeningTime.hour[2] = 16;
	film[0].movieTheaters[1].screeningTime.minute[2] = 00;

	film[0].movieTheaters[1].screeningTime.hour[3] = 18;
	film[0].movieTheaters[1].screeningTime.minute[3] = 30;
	//Film 2 Theater 1 timings
	film[1].movieTheaters[0].screeningTime.hour[0] = 10;
	film[1].movieTheaters[0].screeningTime.minute[0] = 00;

	film[1].movieTheaters[0].screeningTime.hour[1] = 12;
	film[1].movieTheaters[0].screeningTime.minute[1] = 30;

	film[1].movieTheaters[0].screeningTime.hour[2] = 15;
	film[1].movieTheaters[0].screeningTime.minute[2] = 00;

	film[1].movieTheaters[0].screeningTime.hour[3] = 17;
	film[1].movieTheaters[0].screeningTime.minute[3] = 30;
	//Film 2 Theater 2 timings
	film[1].movieTheaters[1].screeningTime.hour[0] = 11;
	film[1].movieTheaters[1].screeningTime.minute[0] = 00;

	film[1].movieTheaters[1].screeningTime.hour[1] = 13;
	film[1].movieTheaters[1].screeningTime.minute[1] = 30;

	film[1].movieTheaters[1].screeningTime.hour[2] = 16;
	film[1].movieTheaters[1].screeningTime.minute[2] = 00;

	film[1].movieTheaters[1].screeningTime.hour[3] = 18;
	film[1].movieTheaters[1].screeningTime.minute[3] = 30;


	//Film 3 Theater 1 Timings
	film[2].movieTheaters[0].screeningTime.hour[0] = 10;
	film[2].movieTheaters[0].screeningTime.minute[0] = 00;

	film[2].movieTheaters[0].screeningTime.hour[1] = 12;
	film[2].movieTheaters[0].screeningTime.minute[1] = 30;

	film[2].movieTheaters[0].screeningTime.hour[2] = 15;
	film[2].movieTheaters[0].screeningTime.minute[2] = 00;

	film[2].movieTheaters[0].screeningTime.hour[3] = 17;
	film[2].movieTheaters[0].screeningTime.minute[3] = 30;
	//Film 3 Theater 2 Timings
	film[2].movieTheaters[1].screeningTime.hour[0] = 11;
	film[2].movieTheaters[1].screeningTime.minute[0] = 00;

	film[2].movieTheaters[1].screeningTime.hour[1] = 13;
	film[2].movieTheaters[1].screeningTime.minute[1] = 30;

	film[2].movieTheaters[1].screeningTime.hour[2] = 16;
	film[2].movieTheaters[1].screeningTime.minute[2] = 00;

	film[2].movieTheaters[1].screeningTime.hour[3] = 18;
	film[2].movieTheaters[1].screeningTime.minute[3] = 30;
	//Film 4 Theater 1 Timings
	film[3].movieTheaters[0].screeningTime.hour[0] = 10;
	film[3].movieTheaters[0].screeningTime.minute[0] = 00;

	film[3].movieTheaters[0].screeningTime.hour[1] = 12;
	film[3].movieTheaters[0].screeningTime.minute[1] = 30;

	film[3].movieTheaters[0].screeningTime.hour[2] = 15;
	film[3].movieTheaters[0].screeningTime.minute[2] = 00;

	film[3].movieTheaters[0].screeningTime.hour[3] = 17;
	film[3].movieTheaters[0].screeningTime.minute[3] = 30;
	//Film 4 Theater 2 Timings
	film[3].movieTheaters[1].screeningTime.hour[0] = 11;
	film[3].movieTheaters[1].screeningTime.minute[0] = 00;

	film[3].movieTheaters[1].screeningTime.hour[1] = 13;
	film[3].movieTheaters[1].screeningTime.minute[1] = 30;

	film[3].movieTheaters[1].screeningTime.hour[2] = 16;
	film[3].movieTheaters[1].screeningTime.minute[2] = 00;

	film[3].movieTheaters[1].screeningTime.hour[3] = 18;
	film[3].movieTheaters[1].screeningTime.minute[3] = 30;

}
void ticketsAvailability(int tickets, int movieNumber, int movieTheater)
{
	char choosingTickets;
	if ((tickets) <= ((film[movieNumber - 1].movieTheaters[movieTheater - 1].theaterInformation.capacity) - (film[movieNumber - 1].movieTheaters[movieTheater - 1].theaterInformation.reserved_seats)))
	{
		cout << "Reservation completed !";
		cash(tickets);
	}
	else if ((film[movieNumber - 1].movieTheaters[movieTheater - 1].theaterInformation.capacity - film[movieNumber - 1].movieTheaters[movieTheater - 1].theaterInformation.reserved_seats) == 0)
	{
		cout << "Incomplete reservation due to full cinema" << endl;

	}
	else if ((film[movieNumber - 1].movieTheaters[movieTheater - 1].theaterInformation.capacity - film[movieNumber - 1].movieTheaters[movieTheater - 1].theaterInformation.reserved_seats) > 0)
	{
		cout << "Incomplete reservation" << endl;
		cout << "Number of tickets available are only " << (film[movieNumber - 1].movieTheaters[movieTheater - 1].theaterInformation.capacity - film[movieNumber - 1].movieTheaters[movieTheater - 1].theaterInformation.reserved_seats) << endl;
		cout << "Do you wish to reserve them?" << endl << "Y/N?";
		cin >> choosingTickets;
		if (choosingTickets == 'Y' || choosingTickets == 'y')
		{
			cout << "How many tickets do you wish to reserve from them?";
			cin >> tickets;
			if (tickets <= (film[movieNumber - 1].movieTheaters[movieTheater - 1].theaterInformation.capacity - film[movieNumber - 1].movieTheaters[movieTheater - 1].theaterInformation.reserved_seats))
				cash(tickets);
			else
				cout << "Number of tickets wanted is more than available number";
		}
		else if (choosingTickets == 'N' || choosingTickets == 'n')
		{

		}
		else
		{
			cout << "Invalid input !" << endl;
		}
	}
}
movie addingMovie()
{
	movie film;
	cout << "Name of the movie:" << endl;
	cin >> film.title;
	cout << "The director:" << endl;
	cin >> film.director;
	cout << "The actors:" << endl;
	for (int i = 0; i < 5; i++)
		cin >> film.actors[i];
	cout << "Rating:" << endl;
	cin >> film.rating;
	cout << "Name of the theaters the movie is showed in";
	cin >> film.movieTheaters[0].theaterInformation.theatre_id;
	cin >> film.movieTheaters[1].theaterInformation.theatre_id;
	cout << "Capacity of the theaters respectively";
	cin >> film.movieTheaters[0].theaterInformation.capacity;
	cin >> film.movieTheaters[1].theaterInformation.capacity;
	film.movieTheaters[0].theaterInformation.reserved_seats = 0;
	film.movieTheaters[1].theaterInformation.reserved_seats = 0;
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << "Enter the screening times of the movie of the theater #" << i + 1;
			cout << " Hour:" << endl;
			cin >> film.movieTheaters[i].screeningTime.hour[j];
			cout << " Minute:" << endl;
			cin >> film.movieTheaters[i].screeningTime.minute[j];
		}
	}

	return film;
}
void listAvailableMovies()
{
	for (int i = 0; i < 4; i++)
	{
		cout << endl << "#" << i + 1 << " " << film[i].title << endl;
		cout << film[i].director << endl;

		for (int j = 0; j < 5; j++)
		{
			cout << film[i].actors[j] << ",\t";
			if (j == 2)
				cout << endl;
		}
		cout << endl << "IMDB rating: " << film[i].rating << endl;
		cout << endl;
	}

}
void listTheatersShowingCertainMovieWithCertainTime()
{
	cout << "Enter the number of the movie\n";
	int theCertainMovie;
	cin >> theCertainMovie;
	if (theCertainMovie == 1 || theCertainMovie == 2 || theCertainMovie == 3 || theCertainMovie == 4)
	{
		for (int k = 0; k < 2; k++)
		{
			cout << film[theCertainMovie - 1].movieTheaters[k].theaterInformation.theatre_id << endl << endl;
			for (int j = 0; j < 4; j++)
			{
				if (k == 0)
				{
					cout << endl << film[theCertainMovie - 1].movieTheaters[k].screeningTime.hour[j];
					cout << ":" << film[theCertainMovie - 1].movieTheaters[k].screeningTime.minute[j] << endl;
				}
				else if (k == 1)
				{
					cout << endl << film[theCertainMovie - 1].movieTheaters[k].screeningTime.hour[j];
					cout << ":" << film[theCertainMovie - 1].movieTheaters[k].screeningTime.minute[j] << endl;
				}
			}
		}
	}
	else
	{
		cout << "Invalid input\n";
	}
}
void theatresShowingCertainMovies()
{
	int movie_num;
	cout << "please enter movie number" << endl;
	cin >> movie_num;
	if (movie_num > 4)
	{
		cout << "Invalid Input !";
		cout << "Please enter a valid movie number : ";
		cin >> movie_num;
	}
	else
	{
		for (int i = 0; i < 2; i++)
		{
			cout << film[movie_num - 1].movieTheaters[i].theaterInformation.theatre_id << endl << endl;
			for (int j = 0; j < 4; j++)
			{
				cout << film[movie_num - 1].movieTheaters[i].screeningTime.hour[j];
				cout << ":";
				cout << film[movie_num - 1].movieTheaters[i].screeningTime.minute[j];
				if (film[movie_num - 1].movieTheaters[i].screeningTime.minute[j] == 0)
					cout << 0;
				cout << endl;
			}
			cout << endl;
		}
	}
}
void listMoviesShowingAtCertainTime()
{
	int theCertainHour, theCertainMinute;
	bool timeNotAvailable = true;
	cout << "Enter the certain hour\t";
	cin >> theCertainHour;
	cout << "Enter the certain minute\t";
	cin >> theCertainMinute;
	cout << endl;
	for (int j = 0; j < 4; j++)
	{
		for (int k = 0; k < 2; k++)
		{
			for (int H = 0; H < 4; H++)
			{
				if (theCertainHour == film[j].movieTheaters[k].screeningTime.hour[H] && theCertainMinute == film[j].movieTheaters[k].screeningTime.minute[H])
				{
					cout << film[j].title << endl << endl;
					timeNotAvailable = false;
				}

			}
		}

	}
	if (timeNotAvailable == true)
		cout << "No available movies at this time" << endl << endl;
}
void comparingTime(int& time, int& movieNumber, int& movieTheater, int& screeningChoice) {
	int tickets;
	char Y_N;
	if (globalTime <= ((film[movieNumber - 1].movieTheaters[movieTheater - 1].screeningTime.hour[screeningChoice - 1] * 60) + (film[movieNumber - 1].movieTheaters[movieTheater - 1].screeningTime.minute[screeningChoice - 1]) + (15)))
	{
		cout << "How many tickets do you want?";
		cin >> tickets;
		ticketsAvailability(tickets, movieNumber, movieTheater);
	}
	else if (globalTime > ((film[movieNumber - 1].movieTheaters[movieTheater - 1].screeningTime.hour[screeningChoice - 1] * 60) + (film[movieNumber - 1].movieTheaters[movieTheater - 1].screeningTime.minute[screeningChoice - 1]) + (15)))
	{
		cout << "You are late for more than 15 minutes than the current show\nSo We suggest for you enter the next show at ";
		if (movieTheater == 1)
		{
			cout << film[movieNumber - 1].movieTheaters[movieTheater].screeningTime.hour[screeningChoice - 1] << ":" << film[movieNumber - 1].movieTheaters[movieTheater].screeningTime.minute[screeningChoice - 1];
			cout << endl << "Do you want to reserve tickets?\t Y/N";
			cin >> Y_N;
			if (Y_N == 'y' || Y_N == 'Y')
			{
				cout << "Enter number of tickets";
				cin >> tickets;
				if (tickets <= 100)
					cash(tickets);
				else
					cout << "There isn't enough tickets available\n";
			}
			else if (Y_N == 'n' || Y_N == 'N')
			{
			}
			else {
				cout << "Invalid Input\n";
			}
		}
		else if (movieTheater == 2)
		{
			cout << film[movieNumber - 1].movieTheaters[movieTheater - 2].screeningTime.hour[screeningChoice] << ":" << film[movieNumber - 1].movieTheaters[movieTheater - 2].screeningTime.minute[screeningChoice];
			cout << endl << "Do you want to reserve tickets?\t Y/N" << endl;
			cin >> Y_N;
			if (Y_N == 'y' || Y_N == 'Y')
			{
				cout << "Enter number of tickets\n";
				cin >> tickets;
				if (tickets <= 75)
					ticketsAvailability(tickets, movieNumber, movieTheater);
				else
					cout << "Not available number of tickets\n";
			}
			else if (Y_N == 'n' || Y_N == 'N')
			{
			}
			else
			{
				cout << "Invalid Input\n";
			}
		}
		else if (screeningChoice == 4 && movieTheater == 2)
		{
			cout << "Sorry, there are no next shows\n";
		}
	}
}
void bookingTicket(int& movieNumber, int& movieTheater, int& numberOfTickets, int& screeningChoice)
{

	cout << "1) Titanic 2) Spider-Man 3) Finding Dory 4) The Conjuring" << endl;
	cout << "Enter the number of the movie you want to watch" << endl;
	cin >> movieNumber;
	if (movieNumber > 4 || movieNumber < 0)
	{
		do {

			cout << "Invalid Input, Please enter a valid number" << endl;
			cin >> movieNumber;

		} while (movieNumber > 4 || movieNumber < 0);;
	}

	cout << "1) Theater1 2) Theater2" << endl;
	cout << "Enter the theater you want to watch the movie in" << endl;
	cin >> movieTheater;
	if (movieTheater == 1)
	{
		cout << "1)10:00 \t 2)12:30 \t 3)15:00 \t 4)17:30" << endl;
	}
	else if (movieTheater == 2)
	{
		cout << "1)11:00 \t 2)13:30 \t 3)16:00 \t 4)18:30" << endl;
	}
	else if (movieTheater > 2 || movieTheater < 0)
	{
		do {

			cout << "Invalid Input, Please enter a valid number" << endl;
			cin >> movieTheater;

		} while (movieTheater > 2 || movieTheater < 0);

	}
	else {
		cout << "Invalid Input, Program Closed";
		exit(0);
	}


	cout << "Enter screening choice" << endl;
	cin >> screeningChoice;
	if (screeningChoice == 1 || screeningChoice == 2 || screeningChoice == 3 || screeningChoice == 4)
		comparingTime(globalTime, movieNumber, movieTheater, screeningChoice);
	else
	{

		do {

			cout << "Invalid Input, Please enter a valid number" << endl;
			cin >> screeningChoice;

		} while (screeningChoice != 1 && screeningChoice != 2 && screeningChoice != 3 && screeningChoice != 4 || screeningChoice < 0);
		comparingTime(globalTime, movieNumber, movieTheater, screeningChoice);



	}

}