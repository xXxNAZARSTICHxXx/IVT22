import 'package:flutter/material.dart';
import 'screens/rover_screen.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 't6project',
      theme: ThemeData(primarySwatch: Colors.blue),
      home: RoverScreen(),
    );
  }
}