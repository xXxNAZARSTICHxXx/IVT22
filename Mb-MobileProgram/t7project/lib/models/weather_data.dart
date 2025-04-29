import 'package:hive/hive.dart';

part 'weather_data.g.dart'; 
@HiveType(typeId: 1)
class WeatherData {
  @HiveField(0)
  final String city;

  @HiveField(1)
  final double temperature;

  WeatherData(this.city, this.temperature);
}