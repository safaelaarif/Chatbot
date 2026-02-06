<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Kimi API Chat</title>
    <style>
        body { font-family: sans-serif; max-width: 600px; margin: 2rem auto; padding: 0 1rem; }
        #chat-box { border: 1px solid #ccc; height: 300px; overflow-y: scroll; padding: 1rem; margin-bottom: 1rem; }
        .input-group { display: flex; gap: 10px; }
        input { flex-grow: 1; padding: 8px; }
        button { padding: 8px 16px; cursor: pointer; background: #007bff; color: white; border: none; border-radius: 4px; }
    </style>
</head>
<body>

    <h2>Chat with Kimi-k2</h2>
    <div id="chat-box"></div>

    <div class="input-group">
        <input type="text" id="userInput" placeholder="Ask something...">
        <button onclick="sendMessage()">Send</button>
    </div>

    <script>
        async function sendMessage() {
            const input = document.getElementById('userInput');
            const chatBox = document.getElementById('chat-box');
            const message = input.value;
            if (!message) return;

            // Display user message
            chatBox.innerHTML += `<p><strong>You:</strong> ${message}</p>`;
            input.value = '';

            try {
                const response = await fetch('https://api.moonshot.cn/v1/chat/completions', {
                    method: 'POST',
                    headers: {
                        'Content-Type': 'application/json',
                        'Authorization': 'Bearer YOUR_MOONSHOT_API_KEY'
                    },
                    body: JSON.stringify({
                        model: "moonshot-v1-8k", // Replace with "kimi-k2-0905" if specifically available in your region
                        messages: [{ role: "user", content: message }]
                    })
                });

                const data = await response.json();
                const reply = data.choices[0].message.content;
                chatBox.innerHTML += `<p><strong>Kimi:</strong> ${reply}</p>`;
            } catch (error) {
                chatBox.innerHTML += `<p style="color:red;">Error: Could not connect to API.</p>`;
            }
            chatBox.scrollTop = chatBox.scrollHeight;
        }
    </script>
</body>
</html>
