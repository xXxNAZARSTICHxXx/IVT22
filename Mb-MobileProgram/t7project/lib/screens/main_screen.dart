import 'package:flutter/material.dart';
import 'package:hive_flutter/hive_flutter.dart';
import '../services/weather_service.dart';
import 'converter_screen.dart';
import 'developer_screen.dart';

class MainScreen extends StatefulWidget {
  const MainScreen({Key? key}) : super(key: key);

  @override
  _MainScreenState createState() => _MainScreenState();
}

class _MainScreenState extends State<MainScreen> {
  final TextEditingController _cityController = TextEditingController();
  final weatherBox = Hive.box('weather_history');
  Map<String, dynamic>? _weatherData;

  Future<void> fetchWeather(String city) async {
    try {
      final weather = await WeatherService.fetchWeather(city);
      if (weather != null) {
        setState(() {
          _weatherData = weather;
          weatherBox.put('last_city', city);
          weatherBox.put('last_temp', _weatherData?['main']['temp']);
        });
      } else {
        ScaffoldMessenger.of(context).showSnackBar(
          SnackBar(content: Text('Город не найден')),
        );
      }
    } catch (e) {
      print('Ошибка получения погоды: $e');
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text('Погода')),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          children: [
            TextField(
              controller: _cityController,
              decoration: InputDecoration(labelText: 'Введите город'),
            ),
            ElevatedButton(
              onPressed: () => fetchWeather(_cityController.text),
              child: Text('Получить погоду'),
            ),
            if (_weatherData != null)
              Column(
                children: [
                  Text('Город: ${_weatherData?['name']}'),
                  Text('Температура: ${_weatherData?['main']['temp']}°C'),
                ],
              ),
            Expanded(
              child: ValueListenableBuilder(
                valueListenable: weatherBox.listenable(),
                builder: (context, box, _) {
                  final history = box.get('last_city') ?? '';
                  final temp = box.get('last_temp') ?? '';
                  return ListView.builder(
                    itemCount: 1,
                    itemBuilder: (context, index) => ListTile(
                      title: Text(history),
                      subtitle: Text('$temp°C'),
                    ),
                  );
                },
              ),
            ),
          ],
        ),
      ),
      bottomNavigationBar: Container(
        padding: EdgeInsets.all(16.0),
        color: Colors.blueGrey[100],
        child: Row(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          children: [
            ElevatedButton(
              onPressed: () {
                Navigator.push(
                  context,
                  MaterialPageRoute(
                    builder: (context) => TemperatureConverterScreen(),
                  ),
                );
              },
              child: Text('Конвертер температур'),
            ),
            ElevatedButton(
              onPressed: () {
                Navigator.push(
                  context,
                  MaterialPageRoute(
                    builder: (context) => DeveloperScreen(),
                  ),
                );
              },
              child: Text('Информация о разработчике'),
            ),
          ],
        ),
      ),
    );
  }
}