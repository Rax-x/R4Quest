# 🌐 A Good HTTP Client for R4

## Overview
R4Quest is a fast, reliable, and lightweight HTTP client designed specifically for the Arduino R4 environment. It provides an intuitive API for making HTTP requests efficiently while maintaining flexibility for developers.

## ⚡ Features
- **Easy-to-use API** – Simplified methods for GET, POST, PUT, DELETE requests.
- **High performance** – Optimized for speed and minimal resource usage.
- **Reliable connections** – Ensures stable and secure HTTP interactions.
- **Customizable** – Supports headers, query parameters, and request configurations.

## 💻 Usage 
Include the library in your Arduino project:
```c++
#include <R4Quest.h>
```

| Function | Description |
|----------|------------|
| `request_get(url, port, body)` | Sends a GET request to the specified URL. |
| `request_post(url, port, body)` | Sends a POST request with an optional body. |
| `request_put(url, port, body)` | Sends a PUT request to update data. |
| `request_delete(url, port, body)` | Sends a DELETE request to remove resources. |
| `set_header(key, value)` | Sets a custom header for the request. |
| `remove_header(header)` | Removes a specified header. |
| `set_authorization(auth)` | Adds an authorization header. |
| `clear_headers()` | Clears all stored headers. |

See ```examples``` for some usage examples.

## 🧩 Contributing
We welcome contributions! Please follow these steps:

1. Fork the repository.
2. Create a new branch ( using <a href="https://medium.com/@abhay.pixolo/naming-conventions-for-git-branches-a-cheatsheet-8549feca2534">this</a> convention).
3. Make your changes and commit them with descriptive messages.
4. Push your changes to your fork.
5. Create a pull request to the main repository.

## ⚖ License
This project is licensed under the GPL-3.0 License. See the LICENSE file for details.

## ⚔ Contact
- For any inquiries or support, please contact <a href="mailto:iannacconegiovanni444@gmail.com"> iannacconegiovanni444@gmail.com </a>.
- Visit my site for more informations about me and my work <a href="https://giovanni-iannaccone.gith
ub.io" target=”_blank” rel="noopener noreferrer"> https://giovanni-iannaccone.github.io </a>