using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class PlayerController : MonoBehaviour {

	public float speed;
	private int count;
	private Rigidbody rb;
	public Text countText;
	public Text winText;

	void Start ()
	{
		rb = GetComponent<Rigidbody>();
		count = 0;
		setCountText();
		winText.text = "";
	}

	void Update ()
	{
        float moveHorizontal = 0.0f;
        float moveVertical = 0.0f;
		if (Application.platform == RuntimePlatform.Android) {
			var touch = Input.GetTouch (0);
			Vector3 touchPos = new Vector3(0.0f, 0.0f, 0.0f);

            touchPos = touch.position;
			int maxX = Screen.width - 1;
			int maxY = Screen.height - 1;

			if (touchPos.x <= maxX && touchPos.x > maxX - 100 && touchPos.y < maxY - 100 && touchPos.y > 100) {
				moveHorizontal = 1.0f;
			} 
			else if (touchPos.x >= 0 && touchPos.x <= 100 && touchPos.y < maxY - 100 && touchPos.y > 100) {
				moveHorizontal = -1.0f;
			} 
			if (touchPos.y <= maxY && touchPos.y > maxY - 100 && touchPos.x < maxX - 100 && touchPos.x > 100) {
                moveVertical = 1.0f;
			}
            else if(touchPos.y >= 0 && touchPos.y <= 100 && touchPos.x < maxX - 100 && touchPos.x > 100) {
                moveVertical = -1.0f;
            }



		} 

   		else {
			moveHorizontal = Input.GetAxis ("Horizontal");
			moveVertical = Input.GetAxis ("Vertical");
		}
		Vector3 movement = new Vector3 (moveHorizontal, 0.0f, moveVertical);

		rb.AddForce (movement * speed);
	}

	void setCountText()
	{
		countText.text = "Count: " + count.ToString ();
		if (count >= 12)
			winText.text = "You Win!";
	}
	void OnTriggerEnter(Collider other) 
	{
		if (other.gameObject.CompareTag ("Pick Up")) {
			other.gameObject.SetActive (false);
			count++;
			setCountText ();
		}
	}
}
