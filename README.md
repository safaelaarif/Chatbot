<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Interface Chat GLM-4.5</title>
    <style>
        body { font-family: sans-serif; background-color: #f4f4f9; display: flex; justify-content: center; padding: 20px; }
        .chat-container { width: 100%; max-width: 600px; background: white; border-radius: 8px; box-shadow: 0 2px 10px rgba(0,0,0,0.1); overflow: hidden; }
        #chat-box { height: 400px; overflow-y: auto; padding: 20px; border-bottom: 1px solid #eee; }
        .input-area { display: flex; padding: 10px; }
        input { flex: 1; padding: 10px; border: 1px solid #ddd; border-radius: 4px; outline: none; }
        button { padding: 10px 20px; background-color: #007bff; color: white; border: none; border-radius: 4px; margin-left: 10px; cursor: pointer; }
        button:hover { background-color: #0056b3; }
        .user-msg { color: #333; font-weight: bold; margin-bottom: 5px; }
        .ai-msg { color: #555; margin-bottom: 15px; background: #e9ecef; padding: 8px; border-radius: 5px; }
    </style>
</head>
<body>

<div class="chat-container">
    <div id="chat-box">
        <div class="ai-msg">Bonjour ! Comment puis-je vous aider avec GLM-4.5 aujourd'hui ?</div>
    </div>
    <div class="input-area">
        <input type="text" id="user-input" placeholder="Posez votre question...">
        <button onclick="sendMessage()">Envoyer</button>
    </div>
</div>

<script>
    async function sendMessage() {
        const input = document.getElementById('user-input');
        const chatBox = document.getElementById('chat-box');
        
        if (input.value.trim() === "") return;

        // Afficher le message utilisateur
        chatBox.innerHTML += `<div class="user-msg">Vous: ${input.value}</div>`;
        
        const prompt = input.value;
        input.value = "";

        // Note : L'appel API réel nécessite une clé API et un backend sécurisé
        chatBox.innerHTML += `<div class="ai-msg"><em>Le modèle GLM-4.5 analyse votre demande...</em></div>`;
        
        chatBox.scrollTop = chatBox.scrollHeight;

        // Simulation de
