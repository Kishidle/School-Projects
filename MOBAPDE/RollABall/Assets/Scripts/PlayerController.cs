using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class PlayerController : MonoBehaviour {

	public float speed;
	private int count;
	private Rigidbody rb;
	public Text countText;
	public Text winText;
    private float moveHorizontal;
    private float moveVertical;

    private bool isLeftPressed;
    private bool isRightPressed;
    private bool isUpPressed;
    private bool isDownPressed;
	void Start ()
	{
		rb = GetComponent<Rigidbody>();
		count = 0;
		setCountText();
		winText.text = "";
        isLeftPressed = false;
        isRightPressed = false;
        isDownPressed = false;
        isUpPressed = false;
        moveHorizontal = 0.0f;
        moveVertical = 0.0f;
	}

	void Update ()
	{
        moveHorizontal = 0.0f;
        moveVertical = 0.0f;
		if (Application.platform == RuntimePlatform.Android) {
            if (isLeftPressed|| isRightPressed|| isDownPressed|| isUpPressed){

                if (isLeftPressed) moveHorizontal = -1.0f;
                else if (isRightPressed) moveHorizontal = 1.0f;
                if (isDownPressed) moveVertical = -1.0f;
                else if (isUpPressed) moveVertical = 1.0f;
            }
            else {
                var touchCount = Input.touchCount;
                for (var t = 0; t < touchCount; t++)
                {

                    var touch = Input.GetTouch(t);
                    Vector3 touchPos = new Vector3(0.0f, 0.0f, 0.0f);
                    touchPos = touch.position;
                    int maxX = Screen.width - 1;
                    int maxY = Screen.height - 1;

                    if (touchPos.x <= maxX && touchPos.x > maxX - 100 && touchPos.y < maxY - 100 && touchPos.y > 100)
                        moveHorizontal = 1.0f;

                    else if (touchPos.x >= 0 && touchPos.x <= 100 && touchPos.y < maxY - 100 && touchPos.y > 100)
                        moveHorizontal = -1.0f;

                    if (touchPos.y <= maxY && touchPos.y > maxY - 100 && touchPos.x < maxX - 100 && touchPos.x > 100)
                        moveVertical = 1.0f;

                    else if (touchPos.y >= 0 && touchPos.y <= 100 && touchPos.x < maxX - 100 && touchPos.x > 100)
                        moveVertical = -1.0f;

                }
            }

		} 

   		else {
            if (isLeftPressed || isRightPressed || isDownPressed || isUpPressed)
            {

                if (isLeftPressed) moveHorizontal = -1.0f;
                else if (isRightPressed) moveHorizontal = 1.0f;
                if (isDownPressed) moveVertical = -1.0f;
                else if (isUpPressed) moveVertical = 1.0f;
            }
            else {
                moveHorizontal = Input.GetAxis("Horizontal");
                moveVertical = Input.GetAxis("Vertical");
            }
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

    public void leftPressed() {
        isLeftPressed = true;
    }

    public void rightPressed() {
        isRightPressed = true;
    }

    public void upPressed() {
        isUpPressed = true;
    }

    public void downPressed() {
        isDownPressed = true;
    }

    public void leftUnPressed() {
        isLeftPressed = false;
    }
    public void rightUnPressed() {
        isRightPressed = false;
    }
    public void upUnPressed() {
        isUpPressed = false;
    }
    public void downUnPressed() {
        isDownPressed = false;
    }

}
