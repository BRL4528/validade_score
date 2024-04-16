#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <curl/curl.h>

// Função para fazer uma solicitação GET para a rota /score/validade
void callScoreValidityRoute(const std::string &apiUrl)
{
    CURL *curl = curl_easy_init();
    if (!curl)
    {
        std::cerr << "Erro ao inicializar o cURL." << std::endl;
        return;
    }

    // URL para a rota /score/validade
    std::string url = apiUrl + "scores/validate";

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 2L); // Tempo limite de conexão em segundos

    // Executar a solicitação
    CURLcode res = curl_easy_perform(curl);

    if (res != CURLE_OK)
    {
        std::cerr << "Erro na solicitação HTTP: " << curl_easy_strerror(res) << std::endl;
    }

    curl_easy_cleanup(curl);
}

int main()
{
    std::string apiUrl = "http://localhost:3333/"; // Substitua pela URL da sua API

    while (true)
    {
        // Verificar a validade do score a cada 3 segundos
        std::cout << "Chamando a rota /scores/validate..." << std::endl;
        
        callScoreValidityRoute(apiUrl);

        // Aguardar 3 segundos antes da próxima chamada
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }

    return 0;
}
