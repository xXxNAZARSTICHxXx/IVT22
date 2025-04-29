import 'dart:convert';
import 'package:http/http.dart' as http;

class WeatherService {
  static const String _apiKey = 'b5be0e380276fe346e66c9b5bc67ae71'; 

  static Future<Map<String, dynamic>?> fetchWeather(String city) async {
  try {
    final url =
        'https://api.openweathermap.org/data/2.5/weather?q=$city&appid=$_apiKey&units=metric&lang=ru';
    final response = await http.get(Uri.parse(url));

    if (response.statusCode == 200) {
      return json.decode(response.body);
    } else {
      print('Ошибка API: ${response.body}');
      throw Exception('Город не найден');
    }
  } catch (e) {
    print('Ошибка получения данных о погоде: $e');
    return null;
  }
}
}