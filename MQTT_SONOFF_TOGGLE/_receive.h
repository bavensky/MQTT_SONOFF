PubSubClient::callback_t on_message_arrived =
[&](const MQTT::Publish & pub) -> void {
  String topic = pub.topic();
  String payload = pub.payload_string();
  String text = topic + " => " + payload;

  
  Serial.print(text);

  if(digitalRead(BUTTON) == 0){
    delay(200);
    digitalWrite(LED, !digitalRead(LED));
    digitalWrite(RELAY, !digitalRead(LED));
  }
  
  if (payload == "11")  {
    digitalWrite(LED, HIGH);
    digitalWrite(RELAY, HIGH);
  }
  else  {
    digitalWrite(LED, LOW);
    digitalWrite(RELAY, LOW);
  }
};
