#include "httplib.h"
using namespace std;
using namespace httplib;

int main() {
	Server server;

	int number = 0;

	server.Get("/count", [&](const Request&, Response& res) {
		number++;
		printf("Counted!\n");
		res.set_content(to_string(number), "text/plain");
	});

	server.Get("/get_count", [&](const Request&, Response& res) {
		// res.set_content("Hello, world!", "text/plain");
		printf("%s\n", ("counter: " + to_string(number)).c_str());
		res.set_content("counter: " + to_string(number), "text/plain");
	});

	server.set_mount_point("/", "./public");

	server.listen("0.0.0.0", 8080);

	return 0;
}