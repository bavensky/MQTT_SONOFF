PubSubClient::callback_t on_message_arrived =
[&](const MQTT::Publish & pub) -> void {
  String topic = pub.topic();
  String payload = pub.payload_string();
  String text = topic + " => " + payload;
  
#define RELAY 12
#define LED   13

  pinMode(RELAY, OUTPUT);
  pinMode(LED, OUTPUT);

  Serial.println(text);
  if (payload == "11")  {
    digitalWrite(LED, HIGH);
    digitalWrite(RELAY, HIGH);
  }
  else  {
    digitalWrite(LED, LOW);
    digitalWrite(RELAY, LOW);
  }
};
