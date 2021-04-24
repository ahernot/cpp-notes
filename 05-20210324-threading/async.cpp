
// template <class Fn, class... Args>
// future<typename result_of<Fn(Args...)>::type> async (launch policy, Fn&& fn, Args&&... args);

// future est une promesse (sera calculé quand appelé (?))


#include <iostream>
#include <future>

// int main(){

//   std::future<int> val = std::async(std::launch::async, []()-> int {
//       std::cout	<< "Hello from future" << std::endl;
//       return 1.;
//     });


//   std::cout << "Hello World from main" << std::endl;

//   int value = val.get();
//   std::cout << "Value = " << value << std::endl;
//   return 0;

// }


int parse_response(const std::string& res) {
    auto j = json::parse(res);
    return j["response"]["numFound"];
}

int main () {

    curl_global_init(CURL_GLOBAL_DEFAULT);

    std::vector<std::string> urls = {
        ""
    }

    for (auto url: urls) {
        std::string out = get_request (url);
        std::cout << "numFound = " << parse_response(out) << std::endl;
    }
}