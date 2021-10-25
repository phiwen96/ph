import Concepts;
import <vector>;

int main()
{
	Number auto a = 10;
	Signed auto b = 2;
	Sequence auto c = 3;
	auto d = std::vector <int> {};

	auto e = d.begin ();

	static_assert (not Input_iterator <decltype (e)>);

	return 0;
}