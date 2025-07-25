#include "httplib.h"
using namespace std;
using namespace httplib;

int main() {
	Server server;

	int number = 0;

	server.Get("/", [&](const Request&, Response& res) {
		res.set_content("Hello, world!", "text/plain");
	});

	server.Get("/count", [&](const Request&, Response& res) {
		number++;
		res.set_content("Counted!", "text/plain");
	});

	server.Get("/get_count", [&](const Request&, Response& res) {
		// res.set_content("Hello, world!", "text/plain");
		res.set_content("counter: " + to_string(number), "text/plain");
	});

	server.listen("0.0.0.0", 8080);

	return 0;
}