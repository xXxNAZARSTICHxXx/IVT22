import 'package:flutter/material.dart';

class SecondScreen extends StatelessWidget {
  final double bmi;

  SecondScreen({required this.bmi});

  String _getBMICategory(double bmi) {
    if (bmi < 16.1) {
      return 'Выраженный дефицит массы тела';
    } else if (bmi < 18.6) {
      return 'Недостаточная (дефицит) масса тела';
    } else if (bmi < 25.1) {
      return 'Нормальный вес';
    } else if (bmi < 30.1) {
      return 'Ожирение I';
    } else if (bmi < 35.1) {
      return 'Ожирение II';
    } else if (bmi < 40.1) {
      return 'Ожирение III';
    } else {
      return 'Ожирение IV (морбидное)';
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Результат ИМТ'),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Text(
              'Ваш ИМТ: ${bmi.toStringAsFixed(2)}',
              style: TextStyle(fontSize: 24, fontWeight: FontWeight.bold),
            ),
            SizedBox(height: 10),
            Text(
              'Категория: ${_getBMICategory(bmi)}',
              style: TextStyle(fontSize: 18),
            ),
            SizedBox(height: 20),
            ElevatedButton(
              onPressed: () {
                Navigator.pop(context);
              },
              child: Text('Вернуться'),
            ),
          ],
        ),
      ),
    );
  }
}
