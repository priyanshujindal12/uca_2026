self.onmessage = async function () {
    try {
        const response = await fetch("https://dummyjson.com/users");
        if (!response.ok) {
            throw new Error("Failed to fetch users");
        }
        const data = await response.json();
        if (!data || data.length === 0) {
            throw new Error("No users returned from the API");
        }
        const users = data.users.map(user => ({
            name: user.firstName,
            status: user.active ? "Active" : "Inactive"
        }));
        self.postMessage(users);
    } catch (error) {
        self.postMessage({
            error: error.message
        });
    }
}; 