import 'package:flutter/material.dart';
import 'package:hive_flutter/hive_flutter.dart';

class TemperatureConverterScreen extends StatefulWidget {
  const TemperatureConverterScreen({Key? key}) : super(key: key);

  @override
  _TemperatureConverterScreenState createState() => _TemperatureConverterScreenState();
}

class _TemperatureConverterScreenState extends State<TemperatureConverterScreen> {
  final TextEditingController _celsiusController = TextEditingController();
  final TextEditingController _fahrenheitController = TextEditingController();
  final historyBox = Hive.box('conversion_history');

  void convertCelsiusToFahrenheit() {
    final celsius = double.tryParse(_celsiusController.text);
    if (celsius != null) {
      setState(() {
        _fahrenheitController.text = ((celsius * 9 / 5) + 32).toStringAsFixed(2);
        saveConversionHistory(celsius, _fahrenheitController.text);
      });
    }
  }

  void convertFahrenheitToCelsius() {
    final fahrenheit = double.tryParse(_fahrenheitController.text);
    if (fahrenheit != null) {
      setState(() {
        _celsiusController.text = ((fahrenheit - 32) * 5 / 9).toStringAsFixed(2);
        saveConversionHistory(fahrenheit, _celsiusController.text);
      });
    }
  }

  void saveConversionHistory(double input, String output) {
    final history = historyBox.get('history', defaultValue: []) as List;
    history.add({'input': input, 'output': output});
    historyBox.put('history', history);
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text('Конвертер температур')),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          children: [
            TextField(
              controller: _celsiusController,
              keyboardType: TextInputType.number,
              decoration: InputDecoration(labelText: 'Температура в °C'),
            ),
            ElevatedButton(
              onPressed: convertCelsiusToFahrenheit,
              child: Text('Конвертировать в °F'),
            ),
            TextField(
              controller: _fahrenheitController,
              keyboardType: TextInputType.number,
              decoration: InputDecoration(labelText: 'Температура в °F'),
            ),
            ElevatedButton(
              onPressed: convertFahrenheitToCelsius,
              child: Text('Конвертировать в °C'),
            ),
            Expanded(
              child: ValueListenableBuilder(
                valueListenable: historyBox.listenable(),
                builder: (context, box, _) {
                  final history = box.get('history', defaultValue: []) as List;
                  return ListView.builder(
                    itemCount: history.length,
                    itemBuilder: (context, index) {
                      final entry = history[index];
                      return ListTile(
                        title: Text('Ввод: ${entry['input']}'),
                        subtitle: Text('Результат: ${entry['output']}'),
                      );
                    },
                  );
                },
              ),
            ),
          ],
        ),
      ),
    );
  }
}