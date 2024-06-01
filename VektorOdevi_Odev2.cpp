// Doğukan Avcı 01.06.2024
#include <iostream>
#include <vector>
#include <cmath>
// Kütüphaneleri tanımlayalım

// Derste öğrendiğimiz Vektör tanımlama ve işlemleri için fonksiyonları yazdım

// Nokta Çarpımı (Scaler Product) Fonksiyonu
float dot_product(const std::vector<float>& vec1, const std::vector<float>& vec2) {
    return vec1[0] * vec2[0] + vec1[1] * vec2[1] + vec1[2] * vec2[2];
}

// Vektör Çıkarma (Vector_Substruction)
std::vector<float> vector_subtraction(const std::vector<float>& vec1, const std::vector<float>& vec2) {
    std::vector<float> result(3);
    result[0] = vec1[0] - vec2[0];
    result[1] = vec1[1] - vec2[1];
    result[2] = vec1[2] - vec2[2];
    return result;
}
/*Ana Fikir: Souls Like bir oyunumuz olsun ve bu oyunda çeşitli mekaniklere sahip bir çok boss var.
Bu oyundaki bosslardan bir tanesinin mekaniği şu şekilde. Boss ile savaşırken belirli zaman aralılarında oyuncu karakteri, bossa arkadasını dönmek zorunda.
Yoksa belirli bir hasar değeri alacak ve bir süreliğine sersemletmeye maruz kalacaktır.  */ 

int main() {
    // Karakterin ve boss'un pozisyonlarını tanımlayalım.
    std::vector<float> character_position = {5.0, 5.0, 0.0};
    std::vector<float> boss_position = {10.0, 10.0, 0.0};

    // Karakterin yön vektörünü tanımla (playerin baktığı yön) 1,0,0 olarak örnek bir değer tanımladım.
    std::vector<float> character_direction = {1.0, 0.0, 0.0};

    int health = 100;
    int damage = 10; // Boss'a bakıldığında alınacak hasar.

    // Karakterden boss'a doğru olan vektörün hesaplanması
    std::vector<float> to_boss_vector = vector_subtraction(boss_position, character_position);

    // Karakterin yön vektörü ile boss'a doğru olan vektörün nokta çarpımını hesapla
    float dot_product_result = dot_product(character_direction, to_boss_vector);

    // Sonuçları ekrana yazdır
    std::cout << "Karakterden Boss'a Doğru Olan Vektör: (" << to_boss_vector[0] << ", " << to_boss_vector[1] << ", " << to_boss_vector[2] << ")\n";
    std::cout << "Nokta Çarpımı Sonucu: " << dot_product_result << "\n";

    // Nokta çarpımı sonucuna göre karakterin boss'a arkasını dönüp dönmediğini kontrol edelim
    // Nokta çarpımı sonucuna göre güvenli yönü belirle
    //Pozitifse, vektörler arasındaki açı 90°'den küçüktür (aynı yöndeler).
    //Negatifse, vektörler arasındaki açı 90°'den büyüktür (zıt yöndeler).

    if (dot_product_result < 0) {
        std::cout << "Güvenli: Karakter boss'a arkasını dönmüş durumda.\n";
    } else {
        std::cout << "Tehlikeli: Karakter boss'a bakıyor, zarar görecek ve belirli bir süre sersemletilecek.\n";
        // Karakter boss'a bakıyorsa can değerini azalt
        health -= damage;
        // SersemletmeFonksiyonu()
        std::cout << "Karakter hasar aldı ve 2 saniye sermsemledi. Kalan can: " << health << "\n";
    }

    // Karakterin can değerini kontrol et
    if (health <= 0) {
        std::cout << "Karakter öldü.\n";
    }

    return 0;
}
